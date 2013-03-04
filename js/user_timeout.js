/*
(function ($) {
  Drupal.behaviors.bibdk_timeout = {
    attach:function (context) {
      $.ajax({
        url: '/ajax/bibdk_timeout',
        success: function(msg) {
          // alert(msg);
          // $('#messages').html('<div class="messages status"><h2 class="element-invisible">Status message</h2>' + msg + '</div>');
        }
      });
    },
    detach:function (context) {
    }
  };
}(jQuery));
*/

(function ($) {
  Drupal.behaviors.bibdk_timeout = {
    attach:function (context) {
      var msg = Drupal.t('Your session has timed out.');
      alert(msg);
      $('#messages').html('<div class="messages status"><h2 class="element-invisible">Status message</h2>' + msg + '</div>');
    },
    detach:function (context) {
    }
  };
}(jQuery));
