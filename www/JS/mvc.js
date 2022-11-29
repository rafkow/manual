@section scripts{ }

@section scripts{
    <script>
    $(document).ready(function () {

    });
    </script>
}

if(ViewBag.Message!=null) {
    <div class="alert alert-danger">
        <strong>Błąd </strong> @ViewBag.Message
    </div>
}

$('.alert').delay(4000).slideUp(200, function () {
    $(this).hide();
});
