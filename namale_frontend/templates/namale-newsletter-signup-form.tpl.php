<?php
/**
 * @file
 * Template file for the Newsletter Form.
 */
?>
<?php print render($form['field_email']); ?>
<?php print render($form['actions']['submit']); ?>
<?php print drupal_render_children($form); ?>