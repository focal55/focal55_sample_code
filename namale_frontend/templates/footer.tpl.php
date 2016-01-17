<?php
/**
 * @file
 * Template file for the Footer Template
 */
$path_to_theme = base_path() . drupal_get_path('theme', 'namale');
?>

<!-- footer.tpl.php -->
<footer>
  <div id="footer">
    <div class="centre">
      <!-- Subscribe / Social | START -->
      <div class="news">
        <div class="title"><span>News & Offers</span></div>
        <div class="subscribe">
          <?php
          $block = module_invoke('webform', 'block_view', 'client-block-101');
          print render($block['content']);
          ?>
        </div>
        <div class="social">
          <a href="https://www.facebook.com/NamaleResort" target="_blank" title="Facebook"><i class="fa fa-facebook"></i></a>
          <a href="http://twitter.com/namaleresort" target="_blank" title="Twitter"><i class="fa fa-twitter"></i></a>
          <a href="http://pinterest.com/namaleresort/" target="_blank" title="Pinterest"><i class="fa fa-pinterest-p"></i></a>
        </div>
      </div>
      <!-- Subscribe / Social | END -->
      <!-- Contact Details | START -->
      <div class="contact">
        <p><strong class="phone">USA: (800) 727-3454<br />INT: (858) 381-5177<br />AUS/NZ: (61) 28 417 2001<br />UK: (44) 20 30 02 38 34</strong>
          <a href="mailto:reservations@namaleresort.com">info@namaleresort.com</a><br /><br />
          <i class="fa fa-map-marker"></i> Hibiscus HWY<br />
          Savusavu Fiji<br />
      </div>
      <!-- Contact Details | END -->
      <div class="dark"></div>
    </div>
  </div>
  <!-- Social Proof -->
  <div id="socialproof">
    <div class="container">
      <div class="row">
        <div class="col-xs-12">
          <div class="awards">
            <div class="award">
              <img src="<?php print $path_to_theme . '/images/footer-icons/hall-of-fame-2015.png'; ?>" alt="Trip Advisor Hall of Fame 2015" />
            </div>
            <div class="award">
              <img src="<?php print $path_to_theme . '/images/footer-icons/ta-2015.png'; ?>" alt="Trip Advisor 2015 Traveler's Choice" />
            </div>
            <div class="award">
              <img src="<?php print $path_to_theme . '/images/footer-icons/ta-2014.png'; ?>" alt="Trip Advisor 2014 Traveler's Choice" />
            </div>
            <div class="award">
              <img src="<?php print $path_to_theme . '/images/footer-icons/ta-2014-certificate-excellence.png'; ?>" alt="Trip Advisor 2014 Certificate of Excellence" />
            </div>
            <div class="award">
              <img src="<?php print $path_to_theme . '/images/footer-icons/ta-2013.png'; ?>" alt="Trip Advisor 2013 Certificate of Excellence" />
            </div>
            <div class="award">
              <img src="<?php print $path_to_theme . '/images/footer-icons/oprah.png'; ?>" alt="Oprah's Favorite Things 2012" />
            </div>
            <div class="award">
              <img src="<?php print $path_to_theme . '/images/footer-icons/wta.png'; ?>" alt="World Travel Awards" />
            </div>
            <div class="award">
              <img src="<?php print $path_to_theme . '/images/footer-icons/spa-finder.png'; ?>" alt="Spa Finder Readers' Choice Category Awards" />
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
  <!-- Footer Links | START -->
  <div id="footerlinks">
    <div class="centre">
      <span>Copyright &copy; <script>var d = new Date(); document.write(d.getFullYear());</script> <strong>Namale Fiji's #1 Resort & Spa</strong></span><a href="/">Home</a><a href="/site-map">Sitemap</a><span><a href="http://www.focal55.com" target="_blank">Developed By Focal55 Inc.</a></span><span></span>
    </div>
  </div>
  <!-- Footer Links | END -->
</footer>
