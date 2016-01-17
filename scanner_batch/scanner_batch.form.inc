<?php

/**
 * @file
 * Form Definitions for the Scanner Batch module.
 */

/**
 * CSV Batch Upload Form.
 */
function scanner_batch_process_form($form, &$form_state) {
  // Defaults.
  $options = NULL;
  $table_title = '';
  $display_process_button = 'none';

  // Add Js.
  drupal_add_js(drupal_get_path('module', 'scanner_batch') . '/theme/js/scanner_batch.js');

  // CSV File Upload fields.
  $form['csv_file_header_row'] = array(
    '#type' => 'checkbox',
    '#title' => 'No headers',
    '#description' => t("Check if the imported CSV file <em>does not</em> start with a header row. Otherwise header row should be Search and Replace."),
  );
  $form['csv_file'] = array(
    '#type' => 'file',
    '#description' => t('Select a file from your local system.'),
  );
  $form['csv_upload'] = array(
    '#type' => 'submit',
    '#value' => 'Import CSV',
    // '#submit' => array('upload_csv_file'),
    '#ajax' => array(
      'callback' => '_scanner_batch_upload_csv_file',
      'wrapper' => 'csv-data-display-table',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  // Set up table header.
  $header = array(
    'search' => t('Search'),
    'replace' => t('Replace'),
    'found' => t('Found'),
  );

  // If previously uploaded a file, load it.
  if (isset($_SESSION['scanner_batch_batch_search_and_replace']['fid'])) {
    // Parse the file.
    $file = file_load($_SESSION['scanner_batch_batch_search_and_replace']['fid']);
    if ($data = _scanner_batch_parse_csv_file($file)) {
      // Build Row Data.
      $options = _scanner_batch_build_options($data, $form_state);
      $table_title = '<div><h3>' . t('Previously Loaded Results from CSV') . ' (' . l($file->filename, file_create_url($file->uri)) . ')</h3></div>';
      // Display the batch process button, since we have data.
      $display_process_button = 'block';
    }
  }

  // Display data from CSV fields.
  $form['display_wrapper'] = array(
    '#type' => 'item',
    '#prefix' => '<div id="csv-data-display-table">',
    '#suffix' => '</div>',
  );
  $form['display_wrapper']['display_csv_table'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No content available.'),
    '#attributes' => array(
      'class' => array('scanner-batch-report'),
    ),
    '#prefix' => !empty($table_title) ? $table_title : '',
  );
  $form['display_wrapper']['process'] = array(
    '#type' => 'submit',
    '#value' => t('Search and Replace'),
    '#submit' => array('_scanner_batch_process_search_and_replace'),
    '#attributes' => array(
      'style' => 'display:' . $display_process_button,
    ),
  );

  return $form;
}

/**
 * AJAX Callback: Upload CSV file.
 */
function _scanner_batch_upload_csv_file($form, &$form_state) {
  // Attempt the upload the file.
  $file = file_save_upload('csv_file', array('file_validate_extensions' => array('csv')), "public://", FILE_EXISTS_REPLACE);
  // If successfully saved.
  if ($file) {
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
    // Parse the file.
    if ($data = _scanner_batch_parse_csv_file($file)) {
      // Update the tableselect form element with new values.
      _scanner_batch_update_display_table($data, $form, $form_state, $file);
      return $form['display_wrapper'];
    }
  }
  else {
    drupal_set_message('No file uploaded.', 'error');
  }
}

/**
 * Helper: Parse CSV File.
 *
 * @param object $file
 *   A file object returned by file_load() or file_save_upload().
 *
 * @return array
 *   Formatted array of the data from CSV.
 */
function _scanner_batch_parse_csv_file($file) {
  $csvdata = NULL;
  // Open and Read the file.
  // Comma or Semicolon seperated, double quote encapsulated string values.
  if ($handle = fopen(drupal_realpath($file->uri), "r")) {
    while (($data = fgetcsv($handle, 0, ',', '"')) !== FALSE) {
      $csvdata[] = $data;
    }
    fclose($handle);
    return $csvdata;
  }
  else {
    return FALSE;
  }
}

/**
 * Helper: Build display form element from parsed CSV data.
 *
 * @param array $data
 *   Array of data from _scanner_batch_parse_csv_file().
 *
 * @param array $form
 *   Drupal form array.
 *
 * @param array $form_state
 *   Drupal $form_state array
 *
 * @param object $file
 *   A file object returned by file_load() or file_save_upload().
 *
 * @return array
 *   Return Drupal $form array with updated display_csv_table element.
 */
function _scanner_batch_update_display_table($data, &$form, &$form_state, $file) {
  // Initialize the options array.
  $display_results = array();

  // Loop through CSV values and build option array.
  if (count($data)) {
    $display_results = _scanner_batch_build_options($data, $form_state);
  }

  // Save FID in session so it can be loaded next time the
  // user returns to page or after batch process finishes.
  $_SESSION['scanner_batch_batch_search_and_replace']['fid'] = $file->fid;

  // Update the Results Table.
  $header = array(
    'search' => t('Search'),
    'replace' => t('Replace'),
    'found' => t('Found'),
  );
  $form['display_wrapper']['display_csv_table'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $display_results,
    '#empty' => t('No content available.'),
    '#multiple' => TRUE,
    '#value' => array(),
    '#attributes' => array(
      'class' => array('scanner-batch-report'),
    ),
    '#prefix' => '<div><h3>' . t('Results from CSV') . ' (' . l($file->filename, file_create_url($file->uri)) . ')</h3></div>',
  );
  $form['display_wrapper']['display_csv_table'] = form_process_tableselect($form['display_wrapper']['display_csv_table']);
  $form['display_wrapper']['process']['#attributes']['style'] = 'display:block';
}

/**
 * Helper: Build Options array for tableselect form element.
 *
 * @param array $data
 *   Array of data from _scanner_batch_parse_csv_file().
 *
 * @param array $form_state
 *   Drupal $form_state array.
 *
 * @return array
 *   Array suitable for FAPI tableselect form element.
 */
function _scanner_batch_build_options($data, &$form_state) {
  // Initialize array to hold tableselect values.
  $options = array();

  // Check if we should remove the header row.
  if (is_array($form_state)) {
    if ((isset($form_state['values']) && !$form_state['values']['csv_file_header_row']) || !isset($form_state['values'])) {
      array_shift($data);
    }
  }

  // Loop through data values.
  foreach ($data as $key => $value) {
    if (!empty($value)) {
      // @TODO: Better why to provide search and replace to batch callback?
      // Concat $value[0] and $value[1] because we will need
      // both during batch processing.
      $index = $value[0] . '|' . $value[1];
      $options[$index] = array(
        'search' => $value[0],
        'replace' => $value[1],
        'found' => array(
          'data' => l(t('Waiting...'), 'admin/content/scanner/batch/ajax/display/' . urlencode($value[0])),
          'class' => 'status',
        ),
      );
    }
  }
  return $options;
}

/**
 * Submit Handler: Process Search and Replace from values imported via CSV file.
 */
function _scanner_batch_process_search_and_replace($form, &$form_state) {
  // Initialize array to store search and replace jobs.
  $jobs = array();

  // Loop through selected items to search and replace.
  if (isset($form_state['values'])) {
    foreach ($form_state['values']['display_csv_table'] as $index => $item) {
      if ($item) {
        $searchreplace = explode('|', $item);
        $jobs[$searchreplace[0]] = $searchreplace[1];
      }
    }
  }

  // If we have jobs to perform.
  if (count($jobs)) {
    // Index the keys from the jobs array for easier looping.
    $keys = array_keys($jobs);

    // Define the Batch.
    // @see scanner_batch.batch.inc for batch functions.
    $batch = array(
      'operations' => array(
        array('scanner_batch_process_update', array($jobs, $keys)),
      ),
      'finished' => 'scanner_batch_search_and_replace_finished',
      'title' => t('Scanner Batch'),
      'init_message' => t('Batch is starting.'),
      'progress_message' => t('Processed @current out of @total.'),
      'error_message' => t('Scanner Batch has encountered an error.'),
      'file' => drupal_get_path('module', 'scanner_batch') . '/scanner_batch.batch.inc',
    );
    batch_set($batch);
  }
  else {
    drupal_set_message(t("No items selected"), 'error');
  }
}
