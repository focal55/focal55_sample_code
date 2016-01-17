<?php
/**
 * @file
 * Default template for Santa Cruz Misc 'Site Summary' block.
 */
?>

<p class="lead">
  <?php if (arg(0) == 'gardens') : ?>
    <?php print t("Show off your beautiful garden!"); ?>
  <?php else : ?>
  <?php print t("Interested in switching out your water-wasting lawn but don't know where to start?"); ?>
  <?php endif; ?>
</p>
<p>
  <?php if (arg(0) == 'gardens') : ?>
    <?php print t("Take a minute and submit your garden, add before and after pictures and tell us what you planted. We will post your project on our Local Inspirations garden page"); ?>
  <?php else : ?>
    <?php print t("Here, you'll find smart gardening ideas, water wise plants, photos of low-water-use gardens, and other resources for creating a beautiful water-efficient landscape."); ?>
  <?php endif; ?>
</p>
<?php if (arg(0) == 'gardens') : ?>
  <p class="text-center"><?php print l(t('Submit your garden'), 'node/add/garden', array('attributes' => array('class' => array('btn', 'btn-santacruz', 'btn-white')))); ?></p>
<?php else : ?>
  <p class="text-center"><?php print l(t('View Gardens'), 'gardens', array('attributes' => array('class' => array('btn', 'btn-santacruz', 'btn-white')))); ?></p>
<?php endif; ?>