<?php
/**
 * @file
 * Alter social media module.
 */

/**
 * Processes variables for social-media-links-platform.tpl.php.
 *
 * @see theme_social_media_links_platform()
 */
function vactory_preprocess_social_media_links_platform(&$variables) {
  if (isset($variables['name'])) {
    $variables['attributes']['class'] = 'icon-' . $variables['name'];
  }
}
