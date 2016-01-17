<?php
/**
 * @file
 * Template File for the Accommodations Nav.
 */
?>

<?php if (isset($rooms)) : ?>
<!-- Sub Navigation | START -->
<ul class="nav">
  <?php foreach($rooms as $room) : ?>
    <li><?php print $room; ?></li>
  <?php endforeach; ?>
</ul>
<?php endif; ?>