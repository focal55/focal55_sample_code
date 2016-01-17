<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_views_pre_render().
 */
function santacruz_views_pre_render(&$view) {
  $row_class =& $view->style_plugin->options['row_class'];
  switch ($view->name) {
    // Alter classes of rows in Resources sections.
    case 'resources':
      // Set Videos up on a 3 column responsive grid.
      if ($view->current_display == 'videos_page') {
        $row_class = 'col-xs-12 col-md-4';
      }
      elseif ($view->current_display == 'plant_pallets_page') {
        $row_class = 'col-sm-6 col-md-3';
      }
      elseif ($view->current_display == 'resource_page') {
        //$row_class = 'col-sm-6 col-md-4';
      }
      break;
    case 'gardens':
      if (in_array($view->current_display, array('gardens_page', 'gotm_page'))) {
        $row_class = 'col-xs-12 col-sm-6 col-md-4';
      }
      break;
  }
}
