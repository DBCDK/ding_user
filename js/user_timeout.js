/*
(function ($) {
  Drupal.behaviors.bibdk_timeout = {
    attach:function (context) {
      $.ajax({
        url: '/ajax/bibdk_timeout',
        success: function(data) {
          alert(data);
          $('#messages').html('<div class="messages status"><h2 class="element-invisible">Status message</h2>' + data + '</div>');
        }
      });
    }
  }
})(jQuery);
*/

(function ($) {
  var msg = Drupal.t('Your session has timed out.');
  alert(msg);
  $('#messages').html('<div class="messages status"><h2 class="element-invisible">Status message</h2>' + msg + '</div>');
})(jQuery);