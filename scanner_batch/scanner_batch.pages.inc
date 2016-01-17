<?php

/**
 * @file
 * Menu Callback definitions for the Scanner Batch module.
 */

/**
 * Preview Results paths.
 */
function scanner_batch_preview() {
  $output = drupal_get_form('scanner_batch_process_form');
  return $output;
}

/**
 * Search for matches
 */
function scanner_batch_search($op, $search) {
  $results = '';
  $output = '';
  $_SESSION['scanner_replace'] = NULL;
  $_SESSION['scanner_preceded'] = NULL;
  $_SESSION['scanner_followed'] = NULL;
  $_SESSION['scanner_mode'] = variable_get('scanner_mode', 0);
  $_SESSION['scanner_wholeword'] = variable_get('scanner_wholeword', 0);
  $_SESSION['scanner_published'] = variable_get('scanner_published', 0);
  $_SESSION['scanner_regex'] = variable_get('scanner_regex', 0);
  unset($_SESSION['scanner_search']);

  // Use Scanner to Search.
  if (!module_exists('scanner')) {
    drupal_set_message('Need to install Scanner Module');
  }
  else {
    $search = urldecode($search);
    $_SESSION['scanner_search'] = str_replace(array('/en', '/cht', '/chs'), '', $search);
    $results = scanner_execute('search');
    // Clear dsms.
    drupal_get_messages();
  }

  // Display options.
  if ($op == 'display') {
    return $results;
  }
  elseif ($op == 'results') {
    // Check Results.
    if (empty($results)) {
      return drupal_json_output(array('results' => 0));
    }
    else {
      // Extract Results count from returned HTML.
      preg_match("/<p[^>]*>(.*?)<\/p>/si", $results, $matches);
      if ($matches[1]) {
        $output = str_replace("Found matches in ", "", str_replace(":", "", str_replace(" fields", "", $matches[1])));
        return drupal_json_output(array('results' => (int)$output));
      }
    }
  }
}