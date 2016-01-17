<?php
/**
 * @file
 * All Packages Block.
 */
?>

<?php if ($packages) : ?>
<!-- all-packages-block.tpl.php -->
  <?php foreach ($packages as $package) : ?>
  <div class="row">
    <div class="col-xs-12">
      <div class="package">
        <div class=""
      </div>
    </div>
  </div>
  <?php endforeach; ?>
<?php endif; ?>

<?php if ($packages) : ?>
<!-- all-packages-block.tpl.php -->
<div id="specials" class="list">
  <div class="caroufredsel_wrapper" style="display: block; text-align: start; float: none; position: relative; top: auto; right: auto; bottom: auto; left: auto; z-index: auto; width: 380px; height: 250px; margin: 0px; overflow: hidden;"><div class="slider" style="text-align: left; float: none; position: absolute; top: 0px; right: auto; bottom: auto; left: 0px; margin: 0px; width: 1140px; height: 250px;">
      <?php foreach ($packages as $package) : ?>
      <div class="item" style="width: 380px;">
        <?php print theme('image_style', array('style_name' => '380x250', 'path' => $package->field_image[LANGUAGE_NONE][0]['uri'], 'width' => '380', 'height' => '250')); ?>
        <div class="details">
          <a href="<?php print drupal_get_path_alias('node/' . $package->nid); ?>">
            <div class="title"><?php print $package->title; ?>
              <?php if (!empty($package->field_sub_title)) : ?>
              <br><span><?php print $package->field_sub_title[LANGUAGE_NONE][0]['value']; ?></span>
              <?php endif; ?>
            </div>
            <?php print $package->body[LANGUAGE_NONE][0]['summary']; ?>
            <div class="button"><span data-hover="View Special">View Special</span></div>
          </a>
        </div>
      </div>
      <?php endforeach; ?>
    </div>
  </div>
  <div class="nav hidden" style="display: none;"><a href="#" class="selected"><span>1</span></a></div>
</div>
<?php endif; ?>