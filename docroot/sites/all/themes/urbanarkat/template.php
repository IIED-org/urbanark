<?php

/**
 * @file
 * Process theme data.
 *
 * Use this file to run your theme specific implimentations of theme functions,
 * such preprocess, process, alters, and theme function overrides.
 *
 * Preprocess and process functions are used to modify or create variables for
 * templates and theme functions. They are a common theming tool in Drupal, often
 * used as an alternative to directly editing or adding code to templates. Its
 * worth spending some time to learn more about these functions - they are a
 * powerful way to easily modify the output of any template variable.
 *
 * Preprocess and Process Functions SEE: http://drupal.org/node/254940#variables-processor
 * 1. Rename each function and instance of "urbanarkat" to match
 *    your subthemes name, e.g. if your theme name is "footheme" then the function
 *    name will be "footheme_preprocess_hook". Tip - you can search/replace
 *    on "urbanarkat".
 * 2. Uncomment the required function to use.
 */


/**
 * Preprocess variables for the html template.
 */
/* -- Delete this line to enable.
function urbanarkat_preprocess_html(&$vars) {
  global $theme_key;

  // Two examples of adding custom classes to the body.

  // Add a body class for the active theme name.
  // $vars['classes_array'][] = drupal_html_class($theme_key);

  // Browser/platform sniff - adds body classes such as ipad, webkit, chrome etc.
  // $vars['classes_array'][] = css_browser_selector();

}
// */


/**
 * Process variables for the html template.
 */
/* -- Delete this line if you want to use this function
function urbanarkat_process_html(&$vars) {
}
// */


/**
 * Override or insert variables for the page templates.
 */
/* -- Delete this line if you want to use these functions
function urbanarkat_preprocess_page(&$vars) {
}
function urbanarkat_process_page(&$vars) {
}
// */


/**
 * Override or insert variables into the node templates.
 */
/* -- Delete this line if you want to use these functions
function urbanarkat_preprocess_node(&$vars) {
}
function urbanarkat_process_node(&$vars) {
}
// */


/**
 * Override or insert variables into the comment templates.
 */
/* -- Delete this line if you want to use these functions
function urbanarkat_preprocess_comment(&$vars) {
}
function urbanarkat_process_comment(&$vars) {
}
// */


/**
 * Override or insert variables into the block templates.
 */
/* -- Delete this line if you want to use these functions
function urbanarkat_preprocess_block(&$vars) {
}
function urbanarkat_process_block(&$vars) {
}
// */

/**
 * Implementation of hook_form_FORM_ID_alter()
 */
 /**
* hook_form_FORM_ID_alter
*/
function urbanarkat_form_search_block_form_alter(&$form, &$form_state, $form_id) {
	//deftext = "Search Urban ARK";
    $form['search_block_form']['#title'] = t('Search Urban ARK'); // Change the text on the label element
    $form['search_block_form']['#title_display'] = 'invisible'; // Toggle label visibilty
    $form['search_block_form']['#size'] = 40;  // define size of the textfield
   // $form['search_block_form']['#default_value'] = t('Search Urban ARK'); // Set a default value for the textfield
   // $form['actions']['submit']['#value'] = t('GO!'); // Change the text on the submit button
   // $form['actions']['submit'] = array('#type' => 'image_button', '#src' => base_path() . path_to_theme() . '/images/search-button.png');

    // Add extra attributes to the text box
   // $form['search_block_form']['#attributes']['onblur'] = "if (this.value == '') {this.value = 'Search Urban ARK';}";
  //  $form['search_block_form']['#attributes']['onfocus'] = "if (this.value == t('Search Urban ARK')) {this.value = '';}";
    // Prevent user from searching the default text
  //  $form['#attributes']['onsubmit'] = "if(this.search_block_form.value==t('Search Urban ARK')){ alert(t('Please enter a search')); return false; }";

    // Alternative (HTML5) placeholder attribute instead of using the javascript
    $form['search_block_form']['#attributes']['placeholder'] = t('Search Urban ARK');
} 