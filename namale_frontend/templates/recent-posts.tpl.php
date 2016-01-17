<?php
/**
 * @file
 * Template File for the Recent Posts.
 */
?>

<?php if (isset($posts)) : ?>
<!-- recent-posts.tpl.php -->
<!-- Recent Blog Posts | START -->
<h2>Recent Posts</h2>
<div class="recent">
  <?php foreach ($posts as $post) : ?>
  <a href="<?php print base_path() . drupal_get_path_alias('node/' . $post->nid); ?>">
    <div class="date">
      <span class="month"><?php print date('M', strtotime($post->field_post_date[LANGUAGE_NONE][0]['value'])); ?></span>
      <span class="day"><?php print date('j', strtotime($post->field_post_date[LANGUAGE_NONE][0]['value'])); ?></span>
    </div>
    <p class="title"><?php print $post->title; ?></p>
    <p><?php print truncate_utf8(strip_tags($post->body[LANGUAGE_NONE][0]['value']), 60, TRUE, TRUE); ?></p>
  </a>
  <?php endforeach; ?>
</div>
<!-- Recent Blog Posts | END -->
<?php endif; ?>