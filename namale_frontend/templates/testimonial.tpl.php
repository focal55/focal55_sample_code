<?php
/**
 * @file
 * Template File for the Testimonials Block.
 */
?>

<?php if (isset($testimonial)) : ?>
<!-- Footer Testimonial | START -->
<div class="footertestimonial hidden-xs">
  <i class="fa fa-quote-left"></i>
  <p class="title"><?php print $testimonial->title; ?></p>
  <p><?php print truncate_utf8($testimonial->body[LANGUAGE_NONE][0]['value'], 600, TRUE); ?>
  <p class="name">&ndash; <strong><?php print $testimonial->field_testimonial_author[LANGUAGE_NONE][0]['value']; ?></strong> <span>(<?php print $testimonial->field_testimonial_location[LANGUAGE_NONE][0]['value']; ?>)</span></p>
  <a href="/testimonials" class="button"><span data-hover="Read Our Testimonials">Read Our Testimonials</span></a>
</div>
<!-- Footer Testimonial | END -->
<?php endif; ?>