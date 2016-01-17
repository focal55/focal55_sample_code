(function($){
var revapi;

$(document).ready(function() {

  revapi = jQuery('.tp-banner').revolution(
    {
      delay:15000,
      startwidth:1170,
      startheight:500,
      hideThumbs:10,
      fullWidth:"off",
      fullScreen:"on",
      fullScreenOffsetContainer: "",
      hideCaptionAtLimit:400
      //hideAllCaptionAtLimit:400
    });

});	//ready
})(jQuery);