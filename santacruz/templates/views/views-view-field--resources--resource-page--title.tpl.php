<?php
/**
 * @file
 * Template for the Title field on Resource List Pages.
 */

$node = $row->_field_data['nid']['entity'];
$output = $node->title;
// Check if external link used.
if (!empty($node->field_external_link)) {
  $output = l($node->title, $node->field_external_link[LANGUAGE_NONE][0]['url'], array('absolute' => TRUE, 'attributes' => array('target' => '_blank')));
}
print $output;
?>