(function ($) {
  Drupal.behaviors.scannerBatch = {
    attach: function(context, settings) {
      // Features management form
      $('table.scanner-batch-report:not(.processed)', context).each(function() {
        $(this).addClass('processed');

        // Check the overridden status of each feature
        Drupal.scannerBatch.checkStatus();
      });
    }
  }

  Drupal.scannerBatch = {
    'checkStatus': function() {
      if ($('table.scanner-batch-report tbody tr').size()) {
        $('table.scanner-batch-report tbody tr').not('.processed').filter(':first').each(function() {
          var elem = $(this);
          $(elem).addClass('processed');
          $(elem).find('td.status a').text('Searching...');
          if ($(this).find('td.status a').size()) {
            var uri = $(this).find('td.status a').attr('href').replace("display", "results");
            if (uri) {
              $.get(uri, [], function(data) {
                $(elem).find('td.status a').text('Found ' +  data.results);
                Drupal.scannerBatch.checkStatus();
              }, 'json');
            }
            else {
              Drupal.scannerBatch.checkStatus();
            }
          }
        });
      }
    }
  };
})(jQuery);