<?php
/**
 * @file
 * Namale Inquiry Form Template.
 */
?>

<!-- namale-inquiry-form.tpl.php -->
<div class="row">
  <div class="col-xs-12">
    <div id="block" class="form">
      <div class="blocktitle"><span>Inquire</span></div>
      <div id="reservations">
        <p><strong>(800) 727-3454</strong><br />
          <a href="mailto:dine@basehotel.com">dine@basehotel.com</a></p>
        <div class="fieldgroup">
          <div class="field calendar"><?php print render($form['arrival']); ?><i class="fa fa-calendar-o"></i></div>
          <div class="field calendar"><?php print render($form['departure']); ?><i class="fa fa-calendar-o"></i></div>
          <div class="field"><?php print render($form['field_first_name']); ?></div>
          <div class="field"><?php print render($form['field_last_name']); ?></div>
          <div class="field"><?php print render($form['field_email']); ?></div>
          <div class="field"><?php print render($form['field_phone']); ?></div>
          <div class="field"><?php print render($form['field_country']); ?></div>
          <div class="field select"><?php print render($form['field_select_bure_type']); ?></div>
          <div class="field select"><?php print render($form['field_hear_about_us']); ?></div>
        </div>
        <?php print render($form['actions']['submit']); ?>
        <?php print drupal_render_children($form); ?>
    </div>
  </div>
</div>