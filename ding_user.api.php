<?php

/**
 * @file
 * Documentation of Ding! user api.
 */

/**
 * Specifies label, form and type of profile2 profile.
 *
 * ->label; label for profile2 tab;
 * ->form; one or array of form(s) to display in tab
 * ->type; profile2 type to get/create
 *
 * @return \stdClass stdobject;
 */
function hook_ding_user_profile2_tabs() {
  $ret = new stdClass();
  $ret->label = t('searchhistory');
  $ret->form = 'bibdk_searchhistory_form';
  $ret->type = 'bibdk_search_history';

  return $ret;
}
?>
