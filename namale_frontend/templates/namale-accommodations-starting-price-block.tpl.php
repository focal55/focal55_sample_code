<?php
/**
 * @file
 * Template for the Starting Price Block.
 */
?>

<!-- namale-accommodations-starting-price-block.tpl.php -->
<?php if (!empty($node->field_room_starting_price)) : ?>
<div class="blocktitle"><a href="contact.php">Stay from <span>$<?php print round($node->field_room_starting_price[LANGUAGE_NONE][0]['value']); ?></span> per night</a></div>
<?php endif; ?>