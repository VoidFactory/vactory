<?php
/**
 * @file
 * Alter HTML page.
 */

/**
 * Implements hook_html_head_alter().
 */
function vactory_html_head_alter(&$head_elements) {
  if (!drupal_is_front_page())
    unset($head_elements["sumome_script_tag"]);
}
