<?php
/**
 * Template file for the Packages List.
 */
?>

<?php if ($packages) : ?>
<!-- namale-packages-list.tpl.php -->
  <?php foreach ($packages as $package) : ?>
  <?php $image = theme('image_style', array('style_name' => '770x500', 'path' => $package->field_image[LANGUAGE_NONE][0]['uri'])); ?>
  <div class="special">
    <div class="img">
      <div class="imgcontainer"><?php print l($image, 'node/' . $package->nid, array('html' => TRUE)); ?></div>
    </div>
    <div class="details">
      <h2><?php print l($package->title, 'node/' . $package->nid); ?></h2>
      <div class="package-description"><?php print $package->body[LANGUAGE_NONE][0]['summary']; ?></div>
      <div class="package-details">
        <ul>
          <li class="booking-code"><strong>ONLINE BOOKING CODE: </strong><?php print $package->field_package_booking_code[LANGUAGE_NONE][0]['value']; ?></li>
          <li class="booking-window"><strong>BOOKING WINDOW: </strong><?php print $package->field_package_booking_window[LANGUAGE_NONE][0]['value']; ?></li>
          <li class="stay-dates"><strong>STAY DATES: </strong><?php print $package->field_packages_stay_dates[LANGUAGE_NONE][0]['value']; ?></li>
        </ul>
      </div>
      <ul class="list-inline action-buttons">
        <li><a class="btn btn-default btn-large" href="<?php print url('node/' . $package->nid); ?>">More Details <span class="glyphicon glyphicon-chevron-right"></span></a></li>
        <?php if (!empty($package->field_package_booking_button)) : ?>
        <li><?php //print $package->field_package_booking_button[LANGUAGE_NONE][0]['value']; ?></li>
        <?php endif; ?>
      </ul>
    </div>
  </div>
    <?php endforeach; ?>
<?php endif; ?>