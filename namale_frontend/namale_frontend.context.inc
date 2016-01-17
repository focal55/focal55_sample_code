<?php
/**
 * @file
 * namale_frontend.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function namale_frontend_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'acommodations';
  $context->description = 'Page specific blocks';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/6' => 'node/6',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'namale_frontend-namale_accommodations_list' => array(
          'module' => 'namale_frontend',
          'delta' => 'namale_accommodations_list',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Page specific blocks');
  t('page');
  $export['acommodations'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'basic_page_blocks';
  $context->description = 'Basic Page Node Blocks. All blocks set and visibility set in the basic page node.';
  $context->tag = 'blocks';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'page' => 'page',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'namale_frontend-namale_page_slideshow' => array(
          'module' => 'namale_frontend',
          'delta' => 'namale_page_slideshow',
          'region' => 'top',
          'weight' => '-10',
        ),
        'namale_frontend-namale_featured_packages' => array(
          'module' => 'namale_frontend',
          'delta' => 'namale_featured_packages',
          'region' => 'bottom',
          'weight' => '-10',
        ),
        'instagram_feed-instagram_feed' => array(
          'module' => 'instagram_feed',
          'delta' => 'instagram_feed',
          'region' => 'bottom',
          'weight' => '-9',
        ),
        'webform-client-block-102' => array(
          'module' => 'webform',
          'delta' => 'client-block-102',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'namale_frontend-namale_packages' => array(
          'module' => 'namale_frontend',
          'delta' => 'namale_packages',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'namale_frontend-namale_recent_posts' => array(
          'module' => 'namale_frontend',
          'delta' => 'namale_recent_posts',
          'region' => 'extras',
          'weight' => '-20',
        ),
        'namale_frontend-namale_testimonial' => array(
          'module' => 'namale_frontend',
          'delta' => 'namale_testimonial',
          'region' => 'extras',
          'weight' => '-19',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic Page Node Blocks. All blocks set and visibility set in the basic page node.');
  t('blocks');
  $export['basic_page_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_pages';
  $context->description = '';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'taxonomy/*' => 'taxonomy/*',
        'blog' => 'blog',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-categories-block' => array(
          'module' => 'views',
          'delta' => 'categories-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-tags-block' => array(
          'module' => 'views',
          'delta' => 'tags-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'webform-client-block-102' => array(
          'module' => 'webform',
          'delta' => 'client-block-102',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'namale_frontend-namale_packages' => array(
          'module' => 'namale_frontend',
          'delta' => 'namale_packages',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('page');
  $export['blog_pages'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blogs';
  $context->description = '';
  $context->tag = 'nodes';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-categories-block' => array(
          'module' => 'views',
          'delta' => 'categories-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-tags-block' => array(
          'module' => 'views',
          'delta' => 'tags-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'webform-client-block-102' => array(
          'module' => 'webform',
          'delta' => 'client-block-102',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'namale_frontend-namale_packages' => array(
          'module' => 'namale_frontend',
          'delta' => 'namale_packages',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('nodes');
  $export['blogs'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'gallery';
  $context->description = 'Gallery Page';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/96' => 'node/96',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'namale_frontend-namale_gallery_page' => array(
          'module' => 'namale_frontend',
          'delta' => 'namale_gallery_page',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Gallery Page');
  t('page');
  $export['gallery'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global';
  $context->description = 'Blocks that show on all pages';
  $context->tag = 'blocks';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'namale_frontend-namale_footer' => array(
          'module' => 'namale_frontend',
          'delta' => 'namale_footer',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks that show on all pages');
  t('blocks');
  $export['global'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home';
  $context->description = '';
  $context->tag = 'blocks';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-homepage-slideshow' => array(
          'module' => 'bean',
          'delta' => 'homepage-slideshow',
          'region' => 'featured',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('blocks');
  $export['home'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage';
  $context->description = 'Blocks for the Homepage';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-4' => array(
          'module' => 'block',
          'delta' => '4',
          'region' => 'homepage_main',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks for the Homepage');
  t('page');
  $export['homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'package_node';
  $context->description = 'Node Specific Blocks';
  $context->tag = 'nodes';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'package' => 'package',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'webform-client-block-102' => array(
          'module' => 'webform',
          'delta' => 'client-block-102',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Node Specific Blocks');
  t('nodes');
  $export['package_node'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'packages';
  $context->description = 'Page specific blocks';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/2' => 'node/2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'namale_frontend-namale_packages_list' => array(
          'module' => 'namale_frontend',
          'delta' => 'namale_packages_list',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Page specific blocks');
  t('page');
  $export['packages'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'rooms';
  $context->description = 'Node Specific Blocks';
  $context->tag = 'nodes';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'room' => 'room',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'namale_frontend-namale_room_starting_price' => array(
          'module' => 'namale_frontend',
          'delta' => 'namale_room_starting_price',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'namale_frontend-namale_accommodations_nav' => array(
          'module' => 'namale_frontend',
          'delta' => 'namale_accommodations_nav',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'webform-client-block-102' => array(
          'module' => 'webform',
          'delta' => 'client-block-102',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'namale_frontend-namale_packages' => array(
          'module' => 'namale_frontend',
          'delta' => 'namale_packages',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'namale_frontend-namale_recent_posts' => array(
          'module' => 'namale_frontend',
          'delta' => 'namale_recent_posts',
          'region' => 'extras',
          'weight' => '-22',
        ),
        'namale_frontend-namale_testimonial' => array(
          'module' => 'namale_frontend',
          'delta' => 'namale_testimonial',
          'region' => 'extras',
          'weight' => '-21',
        ),
        'namale_frontend-namale_footer' => array(
          'module' => 'namale_frontend',
          'delta' => 'namale_footer',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Node Specific Blocks');
  t('nodes');
  $export['rooms'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site_map';
  $context->description = '';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/118' => 'node/118',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-2' => array(
          'module' => 'menu_block',
          'delta' => '2',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'site-map-page',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('page');
  $export['site_map'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'testimonials';
  $context->description = '';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/110' => 'node/110',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'namale_frontend-namale_testimonials_list' => array(
          'module' => 'namale_frontend',
          'delta' => 'namale_testimonials_list',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('page');
  $export['testimonials'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'testimonials_node';
  $context->description = '';
  $context->tag = 'nodes';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'testimonial' => 'testimonial',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'webform-client-block-102' => array(
          'module' => 'webform',
          'delta' => 'client-block-102',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'namale_frontend-namale_packages' => array(
          'module' => 'namale_frontend',
          'delta' => 'namale_packages',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('nodes');
  $export['testimonials_node'] = $context;

  return $export;
}
