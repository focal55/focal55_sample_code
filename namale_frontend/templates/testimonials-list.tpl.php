<?php
/**
 * @file
 * Template file the Testimonials page.
 */
?>
<!-- testimonials-list.tpl.php -->
  <div id="testimonials">
    <figure class="cover">
      <div class="testimonial">
        <?php print theme('image', array('path' => drupal_get_path('theme', 'namale') . '/images/testimonials.jpg', 'width' => '770', 'height' => '500')); ?>
        <div class="details">
          <?php print $testimonial_description_block; ?>
        </div>
      </div>
    </figure>
    <?php if (isset($testimonials)) : ?>
    <?php foreach ($testimonials as $testimonial) : ?>
    <figure>
      <div class="testimonial">
        <?php if (node_access('update', $testimonial)) : ?>
          <div class="contextual-links-wrapper">
            <a class="contextual-links-trigger" href="#">Configure</a>
            <ul class="contextual-links">
              <li class="block-configure first last">
                <a href="/node/<?php print $testimonial->nid; ?>/edit?destination=node/110">Edit Testimonial</a>
              </li>
            </ul>
          </div>
        <?php endif; ?>
        <i class="fa fa-quote-left"></i>
        <h2><?php print $testimonial->title; ?></h2>
        <?php $body = field_view_field('node', $testimonial, 'body', array('label' => 'hidden')); print drupal_render($body); ?>
        <p class="name">&ndash; <strong><?php print $testimonial->field_testimonial_author[LANGUAGE_NONE][0]['value']; ?></strong> <span>(<?php print $testimonial->field_testimonial_location[LANGUAGE_NONE][0]['value']; ?>)</span></p>
      </div>
    </figure>
    <?php endforeach; ?>
    <?php endif; ?>
  </div>
