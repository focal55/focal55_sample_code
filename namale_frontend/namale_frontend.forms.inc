<?php

/**
 * @file
 * Form definitions for the Namale Frontend module.
 */

/**
 * Newsletter Signup form.
 */
function namale_newsletter_signup_form() {
  global $user;
  global $language;
  module_load_include('inc', 'node', 'node.pages');
  $node_type = 'newsletter_signup';
  $form_id = $node_type . '_node_form';
  $node = new stdClass();
  $node->uid = $user->uid;
  $node->name = (isset($user->name) ? $user->name : '');
  $node->type = $node_type;
  $node->language = LANGUAGE_NONE;
  node_object_prepare($node);
  $form = drupal_get_form($form_id, $node);

  // Hide node form fields.
  _namale_forms_hide_node_options($form);

  // Change form action so submit redirects back here.
  $form['#action'] = url(drupal_get_path_alias($_GET['q']), array('query' => array('destination' => $_GET['q'])));

  // Add placeholders.
  $form['field_first_name'][LANGUAGE_NONE][0]['value']['#attributes']['placeholder'] = t('First Name');
  $form['field_last_name'][LANGUAGE_NONE][0]['value']['#attributes']['placeholder'] = t('Last Name');
  $form['field_email'][LANGUAGE_NONE][0]['#title'] = '';
  $form['field_email'][LANGUAGE_NONE][0]['value']['#attributes']['placeholder'] = t('Email');
  $form['actions']['submit']['#value'] = 'Sign Up';

  // Hide.
  $form['field_first_name']['#access'] = FALSE;
  $form['field_last_name']['#access'] = FALSE;

  // Add CSS.
  $form['#attached']['css'][] = drupal_get_path('theme', 'namalefiji') . '/css/forms.css';

  // Template.
  $form['#theme'] = 'namale_newsletter_signup_form';

  return $form;
}

/**
 * Newsletter Signup form.
 */
function namale_inquiry_signup_form() {
  global $user;
  global $language;
  module_load_include('inc', 'node', 'node.pages');
  $node_type = 'inquiry_signup';
  $form_id = $node_type . '_node_form';
  $node = new stdClass();
  $node->uid = $user->uid;
  $node->name = (isset($user->name) ? $user->name : '');
  $node->type = $node_type;
  $node->language = LANGUAGE_NONE;
  node_object_prepare($node);
  $form = drupal_get_form($form_id, $node);

  // Hide node form fields.
  _namale_forms_hide_node_options($form);

  // Change form action so submit redirects back here.
  $form['#action'] = url(drupal_get_path_alias($_GET['q']), array('query' => array('destination' => $_GET['q'])));
  $form['actions']['submit']['#attributes']['class'][] = 'btn btn-success';

  // Add placeholders.
  $form['field_first_name'][LANGUAGE_NONE][0]['value']['#attributes']['placeholder'] = t('First Name');
  $form['field_last_name'][LANGUAGE_NONE][0]['value']['#attributes']['placeholder'] = t('Last Name');
  $form['field_email'][LANGUAGE_NONE][0]['value']['#attributes']['placeholder'] = t('Email');
  $form['field_phone'][LANGUAGE_NONE][0]['value']['#attributes']['placeholder'] = t('Phone Number');
  $form['field_country'][LANGUAGE_NONE][0]['value']['#attributes']['placeholder'] = t('Country');
  $form['field_select_bure_type'][LANGUAGE_NONE]['#options']['_none'] = t('Select Bure Type');
  $form['field_hear_about_us'][LANGUAGE_NONE]['#options']['_none'] = t('How did you hear about us');

  // Required.
  $form['field_first_name']['#required'] = TRUE;


  // Hide Fields.
  $form['field_arrival']['#access'] = FALSE;
  $form['field_departure']['#access'] = FALSE;
  $form['field_comment']['#access'] = FALSE;

  // Fake Date Fields, so we can use jquery.
  $form['arrival'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#attributes' => array(
      'placeholder' => t('Arrival Date'),
      'id' => 'arrivaldate',
    )
  );
  $form['departure'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#attributes' => array(
      'placeholder' => t('Departure Date'),
      'id' => 'departuredate',
    )
  );

  // Template.
  $form['#theme'] = 'namale_inquiry_signup_form';

  // Add CSS.
  $form['#attached']['css'][] = drupal_get_path('theme', 'namalefiji') . '/css/forms.css';

  // Add Validation.
  array_unshift($form['#validate'], '_namale_frontend_inquiry_form_validation');

  return $form;
}

/**
 * Validate Handler: Namale Inquiry Sign Up Form.
 */
function _namale_frontend_inquiry_form_validation($form, &$form_state) {
  // Move fake date fields into drupal fields.
  $form_state['values']['field_arrival'][LANGUAGE_NONE][0]['value'] = $form_state['values']['arrival'];
  $form_state['values']['field_departure'][LANGUAGE_NONE][0]['value'] = $form_state['values']['departure'];
}

/**
 * Helper function to hide node options.
 */
function _namale_forms_hide_node_options(&$form) {
  $form['revision_information']['#access'] = FALSE;
  $form['author']['#access'] = FALSE;
  $form['options']['#access'] = FALSE;
  $form['path']['#access'] = FALSE;
  $form['comment_settings']['#access'] = FALSE;
}