selectors:
  $("p") - get element by type
  $("#id") - get element by id
  $(".class") - get element by class
  $(this).attr('id')

$("p").click(function(){
  alert("The paragraph was clicked.");
});

console.log('your message');

var catalogs = [];
var catalogs_dict = {};

@:properties_selected = @Html.Raw(Json.Encode(Model.SelectedProperties));

// przypisy z .Net Framework
@:catalogs.push("@item.Number @item.Name");
@:catalogs_dict[@item.ID] = "@item.Number @item.Name";
var dict = {};
@foreach(var item in Model.Relations) { // item.Value  <int[]>
    @:dict[@item.Key] = @Html.Raw(Json.Encode(item.Value));
}

//  zaladuj co cookies pozycje strony i wczytaj po przeładowaniu
$(window).scrollTop(localStorage['scrollposition']);
localStorage['scrollposition'] = $(window).scrollTop();

console.log("[" + index + "] jest " + element);
