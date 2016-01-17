<?php

/**
 * @file
 * Batch Definitions for Scanner Batch module.
 */

/**
 * Process the batch.
 */
function scanner_batch_process_update($jobs, $keys, &$context) {
  // Set starting values that track progress of the batch.
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = count($jobs);
    $context['sandbox']['currently_looking_for'] = $keys[0];
  }

  // Run search and replace on current job.
  $success = _scanner_batch_execute_search_and_replace($keys[$context['sandbox']['progress']], $jobs[$keys[$context['sandbox']['progress']]]);

  // Update our progress information.
  if ($success) {
    $context['results'][] = $keys[$context['sandbox']['progress']] . " replaced with " . $jobs[$keys[$context['sandbox']['progress']]];
  }
  $context['sandbox']['progress']++;
  $context['sandbox']['currently_looking_for'] = $keys[$context['sandbox']['progress']];
  $context['message'] = t('@count/@max | Searching for @search and replacing with @replace', array(
    '@count' => $context['sandbox']['progress'],
    '@max' => $context['sandbox']['max'],
    '@search' => $context['sandbox']['currently_looking_for'],
    '@replace' => $jobs[$keys[$context['sandbox']['progress']]])
  );

  // Inform the batch engine that we are not finished,
  // and provide an estimation of the completion level we reached.
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

/**
 * Batch 'finished' callback.
 */
function scanner_batch_search_and_replace_finished($success, $results, $operations) {
  // Reset drupal_set_messages() bc scanner sets some message
  // irrelevant to us.
  drupal_get_messages();

  if ($success) {
    // Here we do something meaningful with the results.
    $message = count($results) . ' processed.';
    $message .= theme('item_list', $results);
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array(
      '%error_operation' => $error_operation[0],
      '@arguments' => print_r($error_operation[1], TRUE))
    );
  }
  drupal_set_message($message);
}

/**
 * Preform the Search and Replace.
 *
 * @param string $search
 *   Search string value.
 *
 * @param string $replace
 *   Replace string value.
 *
 * @return bool
 *   If Scanner API scanner_execute() returns something
 *   everything worked, if it returns NULL it did nothing.
 */
function _scanner_batch_execute_search_and_replace($search, $replace) {
  // Set up the Session values that Scanner module needs.
  $_SESSION['scanner_preceded'] = NULL;
  $_SESSION['scanner_followed'] = NULL;
  $_SESSION['scanner_mode'] = variable_get('scanner_mode', 0);
  $_SESSION['scanner_wholeword'] = variable_get('scanner_wholeword', 0);
  $_SESSION['scanner_published'] = variable_get('scanner_published', 0);
  $_SESSION['scanner_regex'] = variable_get('scanner_regex', 0);
  unset($_SESSION['scanner_search']);

  // Allow other modules to alter the search value.
  // Use this in case, you want to programmatically modify the
  // search or replace string value.
  module_invoke_all('example_thingy', $search, $replace);
  drupal_alter('scanner_batch_modify_strings', $search, $replace);


  // Set Session variables for search and replace values.
  $_SESSION['scanner_search'] = $search;
  $_SESSION['scanner_replace'] = $replace;

  // Run Search and Replace.
  $results = scanner_execute('search');

  // Return True if Scanner was successful.
  if ($results = scanner_execute('replace')) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

