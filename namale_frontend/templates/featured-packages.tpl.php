<?php
/**
 * @file
 * Template file for the Featured Packages Block.
 */
?>

<!-- feature-packages.tpl.php -->
<div id="extras">
  <div class="centre">
    <div id="specials" class="list" style="margin-bottom:0;">
      <div class="back">
        <div class="slider">
          <?php foreach ($packages as $package) : ?>
          <div class="item">
            <?php print theme('image_style', array('style_name' => '1200x400', 'path' => $package->field_image[LANGUAGE_NONE][0]['uri'], 'width' => '1200', 'height' => '400')); ?>
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
      <div class="nav"></div>
    </div>
  </div>
</div>

<!-- Feature List | END -->