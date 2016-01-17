<?php
/**
 * @file
 * Template file for the homepage slideshow.
 */
?>

<?php if ($slides) : ?>
<!-- homepage-slider.tpl.php -->
<div id="featured">
  <div class="slider">
    <?php foreach ($slides as $slide) : ?>
    <div class="item">
      <div class="details">
<!--        <div class="title"><span>--><?php //print $slide['caption']; ?><!--</span></div>-->
        <div class="buttoncontainer"><a href="<?php print $slide['link']['url']; ?>" class="button"><span data-hover="<?php print $slide['link']['title']; ?>"><?php print $slide['link']['title']; ?></span></a></div>
      </div>
      <?php print $slide['image']; ?>
    </div>
    <?php endforeach; ?>
  </div>
  <div class="centre">
    <div class="nav">
      <a class="prev"><i class="fa fa-chevron-left"></i></a>
      <a class="next"><i class="fa fa-chevron-right"></i></a>
    </div>
  </div>
</div>
<?php endif; ?>