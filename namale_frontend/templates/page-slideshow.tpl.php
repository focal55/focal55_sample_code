<?php
/**
 * @file
 * Template file for the Page Slideshow.
 */
?>

<?php if ($images) : ?>
<!-- page-slideshow.tpl.php -->
<div id="slideshow">
  <div class="slider">
    <?php foreach ($images as $image) : ?>
    <div class="item"><?php print $image; ?></div>
    <?php endforeach; ?>
  </div>
  <div class="nav">
    <a class="prev"><i class="fa fa-chevron-left"></i></a>
    <a class="next"><i class="fa fa-chevron-right"></i></a>
  </div>
</div>
<?php endif; ?>