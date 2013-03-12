(function ($) {
  Drupal.behaviors.bibdk_timeout = {
    attach:function (context) {
      var msg = Drupal.t('Your session has timed out.');
      alert(msg);
      $('#messages').html('<div class="messages status"><h2 class="element-invisible">Status message</h2>' + msg + '</div>');
      $('a[href$="/user/logout"]').html(Drupal.t('Log in'));
      var value = $('a[href$="/user/logout"]').attr('href').replace("/logout", "/login");
      $('a[href$="/user/logout"]').attr('href',value);
    },
    detach:function (context) {
    }
  };
}(jQuery));
