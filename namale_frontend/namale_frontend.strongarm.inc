<?php
/**
 * @file
 * namale_frontend.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function namale_frontend_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_jquery_version';
  $strongarm->value = '1.7';
  $export['jquery_update_jquery_version'] = $strongarm;

  return $export;
}
