<?php
/**
 * @file
 * Custom template for Santa Cruz Misc 'Site Credits' block.
 */
?>

<div class="social-media-icons">
  <a href="https://www.facebook.com/pages/West-Basin-Municipal-Water-District/186785268027122?sk=wall" target="_blank"><span class="sm-icon sm-icon-facebook">Facebook</span></a>
  <a href="https://twitter.com/WestBasin" target="_blank"><span class="sm-icon sm-icon-twitter">Twitter</span></a>
  <a href="http://instagram.com/westbasin" target="_blank"><span class="sm-icon sm-icon-instagram">Instagram</span></a>
  <a href="https://www.linkedin.com/company/west-basin-municipal-water-district" target="_blank"><span class="sm-icon sm-icon-linkedin">LinkedIn</span></a>
  <a href="http://www.pinterest.com/WestBasin/" target="_blank"><span class="sm-icon sm-icon-pinterest">Pinterest</span></a>
</div>

<div class="newsletter-signup-link">
  <a href="http://www.westbasin.org/enewsletter">Sign up for our newsletter</a>
</div>

<div class="copyright">
<?php print t('&copy; @year @name', array(
  '@year' => date('Y'),
  '@name' => variable_get('site_name', '')
)); ?>
</div>

<div class="address-phone-fax">
  <address>17140 South Avalon Blvd Suite 210 Carson, CA 90746-1296</address> <span class="phone-number">Phone: (310) 217-2411</span> <span class="fax-number">Fax: (310) 217-2414</span>
</div>
