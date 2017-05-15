<?php
/**
 * @file
 * Code for menus.
 */

/**
 * Implements hook_theme_registry_alter().
 */
function vactory_theme_registry_alter(&$theme_registry) {
  $theme_registry['menu_tree']['function'] = '_vactory_menu_tree';
  $theme_registry['menu_link']['function'] = '_vactory_menu_link';
}

/**
 * Implements theme_menu_tree__[MENU NAME].
 */
function _vactory_menu_tree($variables) {
  global $_menu_level;

  $class = ($_menu_level == 1) ? 'parent-ul item-level-' . $_menu_level : 'child-ul item-level-' . $_menu_level;
  return '<div class="menu-wrapper"><ul class="menu nav ' . $class . '">' . $variables['tree'] . '</ul></div>';
}


/**
 * Implements theme_menu_link().
 */
function _vactory_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if (!empty($element['#below'])) {
    $sub_menu = drupal_render($element['#below']);
    $element['#localized_options']['html'] = TRUE;
    $element['#title'] .= '<span class="caret"></span>';
  }

  // Fix for active class.
  if (($element['#href'] == current_path() || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']) || $element['#localized_options']['language']->language == $language_url->language)) {
    $element['#attributes']['class'][] = 'active';
  }

  // Add active class to li if active trail.
  if (in_array('active-trail', $element['#attributes']['class'])) {
    $element['#attributes']['class'][] = 'active';
  }

  // Add a unique class using the title.
  $title = strip_tags($element['#title']);
  $element['#attributes']['class'][] = 'menu-link-' . drupal_html_class($title);

  if ($element['#original_link']['menu_name'] == 'menu-v-header-v5-navigation') {
    $element['#title'] = '<span>' . $element['#title'] . '</span>';
    $element['#localized_options']['html'] = TRUE;
  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
