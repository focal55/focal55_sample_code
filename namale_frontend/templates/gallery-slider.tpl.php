<?php
/**
 * @file
 * Template file for the Gallery Slider.
 */
?>
<?php if ($images) : ?>
<div id="galleryslider" class="manual">
  <div class="slidecontainer">
    <div class="slider">
      <?php foreach ($images as $image) : ?>
        <?php print $image; ?>
      <?php endforeach; ?>
    </div>
    <div class="centre">
      <div class="nav">
        <a class="prev"><i class="fa fa-chevron-left"></i></a>
        <a class="next"><i class="fa fa-chevron-right"></i></a>
      </div>
    </div>
  </div>
  <a href="/gallery" class="button"><span data-hover="Browse Our Gallery">Browse Our Gallery</span></a>
</div>
<?php endif; ?>