<?php
/**
 * @file
 * Custom View template to display a list of rows.
 *
 * Adds responsive Bootstrap container (.container-fluid) for each Unformatted view.
 *
 * @ingroup views_templates
 */
?>

<div class="container-fluid">
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div class="<?php if ($classes_array[$id]) { print ' ' . $classes_array[$id]; } ?>">
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
</div>
