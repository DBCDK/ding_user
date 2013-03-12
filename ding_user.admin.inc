<?php

/**
 * @file
 * Admin settings for ding user
 */

/**
 * timeout settings.
 */
function ding_user_lifetime() {

  $lifetime = variable_get('ding_user_creds_lifetime', 7200);
  $lifetype = variable_get('ding_user_creds_lifetype', 'initial');

  $form['ding_user_admin'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Ding user settings', array(), array('context' => 'ding_user')),
    '#description'  => t('Edit Ding user settings.', array(), array('context' => 'ding_user')),
    '#tree'         => TRUE,
  );

  $form['ding_user_admin']['creds_lifetime'] = array(
    '#type'           => 'textfield',
    '#default_value'  => $lifetime,
    '#title'          => t('User timeout (in seconds)', array(), array('context' => 'ding_user')),
    '#description'    => t('How long does the user\'s session last?', array(), array('context' => 'ding_user')),
    '#size'           => 24,
  );

  $options = array('refresh' => t('after each page load', array(), array('context' => 'ding_user')), 'initial' => t('after initial login', array(), array('context' => 'ding_user')));
  $form['ding_user_admin']['creds_lifetype'] = array(
    '#type' => 'radios',
    '#title' => t('User timeout type'),
    '#default_value' => $lifetype,
    '#options' => $options,
    '#description' => t('Is the timeout refreshed after each page load, or is it only set once, at login?.', array(), array('context' => 'ding_user')),
  );

  $form['ding_user_admin']['actions'] = array('#type' => 'actions');
  $form['ding_user_admin']['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}


/**
 * Validation handler for ding_user_lifetime.
 */
function ding_user_lifetime_validate($form, &$form_state) {

  if ( (int)$form_state['values']['ding_user_admin']['creds_lifetime'] <= 0 ) {
    form_set_error('creds_lifetime',
      t('User timeout must be greater than 0.',
        array(),
        array('context' => 'ding_user:error')));
  }

  if ( $form_state['values']['ding_user_admin']['creds_lifetype'] != 'refresh' && $form_state['values']['ding_user_admin']['creds_lifetype'] != 'initial' ) {
    form_set_error('creds_lifetype',
      t('User timeout type is not valid.',
        array(),
        array('context' => 'ding_user:error')));
  }
}

/**
 * Submit handler for ding_user_lifetime();
 */
function ding_user_lifetime_submit($form, &$form_state) {
  $lifetime = (int)$form_state['values']['ding_user_admin']['creds_lifetime'];
  variable_set('ding_user_creds_lifetime', $lifetime);

  $options = array('refresh' => t('after each page load', array(), array('context' => 'ding_user')), 'initial' => t('after initial login', array(), array('context' => 'ding_user')));
  $lifetype = $form_state['values']['ding_user_admin']['creds_lifetype'];
  variable_set('ding_user_creds_lifetype', $lifetype);

  drupal_set_message(t("User timeout set to @seconds seconds (~@minutes minutes) @type.", array('@seconds' => $lifetime, '@minutes' => round($lifetime/60), '@type' => $options[$lifetype]), array('context' => 'ding_user')));
}
