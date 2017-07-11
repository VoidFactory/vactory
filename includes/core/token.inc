<?php
/**
 * @file
 * Code for tokens.
 */

/**
 * Implements hook_token_info().
 */
function vactory_token_info() {
  $info['types']['vactory'] = array( // define main group
    'name'        => t('Vactory'),
    'description' => t('Vactory Tokens'),
  );

  $info['tokens']['vactory']['site-logo'] = array( // first level token
    'name'        => t('Site logo'),
    'description' => t('The logo of the site.'),
  );

  return $info;
}

/**
 * Implements hook_tokens().
 */
function vactory_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  foreach ($tokens as $name => $original) {
    if ($name == 'site-logo') {
      $replacements[$original] = theme('image', array('path' => theme_get_setting('logo', variable_get('theme_default', 'starter1'))));
    }
  }

  return $replacements;
}
