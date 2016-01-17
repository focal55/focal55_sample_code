<?php
/**
 * @file
 * Gallery Page.
 */
?>

<?php if ($images) : ?>
<!-- gallery-page.tpl.php -->
  <div id="gallery">
    <?php foreach ($images as $image) : ?>
      <figure class="<?php print $image['class']; ?>">
        <a href="<?php print $image['path']; ?>">
          <span><?php print $image['title']; ?></span>
          <?php print $image['img']; ?>
        </a>
      </figure>
    <?php endforeach; ?>
  </div>
<?php endif; ?>