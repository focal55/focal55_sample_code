<?php
/**
 * Template file for the Rooms List.
 */
?>

<!-- namale-accomodations-list.tpl.php -->
<section id="rooms" class="list hover">
  <?php if (!empty($rooms)) : ?>
  <?php foreach($rooms as $room) : ?>
  <div class="item">
    <?php if (!empty($room->field_images)) : ?>
    <div class="imgcontainer"><?php print theme('image_style', array('style_name' => '1200x400', 'path' => $room->field_images[LANGUAGE_NONE][0]['uri'])); ?></div>
    <?php endif; ?>
    <div class="details">
      <h3 class="title"><?php print $room->title; ?>
        <?php if (!empty($room->field_room_starting_price)) : ?>
        <br>
        <span>Stay from $<?php print $room->field_room_starting_price[LANGUAGE_NONE][0]['value']; ?> per night</span>
        <?php endif; ?>
      </h3>
      <?php if (!empty($room->body)) : ?>
      <?php print $room->body[LANGUAGE_NONE][0]['safe_summary']; ?>
      <?php endif; ?>
      <div class="button-container">
        <a class="btn btn-success room-inquiry" href="#" data-room="<?php print $room->title; ?>" data-toggle="modal" data-target="#inquireModal"><span data-hover="View Room">Inquire</span></a>
        <a class="btn btn-success" href="<?php print base_path() . drupal_get_path_alias('node/' . $room->nid); ?>"><span data-hover="View Room">View Room</span></a>
      </div>
    </div>
  </div>
  <?php endforeach; ?>
    <!-- Modal -->
    <div class="modal fade" id="inquireModal" tabindex="-1" role="dialog" aria-labelledby="inquireModalLabel">
      <div class="modal-dialog" role="document">
        <div class="modal-content">
          <div class="modal-header">
            <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
            <h4 class="modal-title" id="myModalLabel">Inquiry</h4>
          </div>
          <div class="modal-body">
            <?php
            $block = module_invoke('webform', 'block_view', 'client-block-102');
            print render($block['content']);
            ?>
          </div>
        </div>
      </div>
    </div>
  <?php endif; ?>
</section>