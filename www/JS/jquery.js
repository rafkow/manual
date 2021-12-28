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
// Html.Raw naprawia błędy z kodowaniem znkaów utf-8
@:mounths.push('@Html.Raw(item)');
//  zaladuj co cookies pozycje strony i wczytaj po przeładowaniu
$(window).scrollTop(localStorage['scrollposition']);
localStorage['scrollposition'] = $(window).scrollTop();

localStorage.removeItem('scrollposition');

console.log("[" + index + "] jest " + element);

// automatyczne zapisywanie checkboxów
<input id="@string.Format("swp_chb{0}", ix*3+2)" type="checkbox" class="swp_chb" name="@(ix*3+2)" />

$('.swp_chb').each(function () {
            if ($(this).prop("checked") == true) {
                swp_set.push($(this).attr('name'));
            }
        });
//Array.from(prop_set)
$('#Sheet_Securing_work_place_set').attr('value', Array.from(swp_set));
// przypisz zaznaczone elementy właściwości do obiektu MCV
$('#Sheet_SelectedProperties').attr("value", Array.from(prop_set));
// zapisz listę pracowników wykonujących pracę
$('#Sheet_Workers').attr("value", Array.from(workers_set));
