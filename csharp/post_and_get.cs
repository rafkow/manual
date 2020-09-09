@using(Html.BeginForm("TakeImage", "Home", new { item_no = Model.Item.SK_NO }, FormMethod.Post , new { enctype = "multipart/form-data"  })) {
    @Html.TextBox("image","", new { type = "file"})
    <input class="btn btn-primary" type="submit" value="Upload"/>
}

[HttpPost]
[Route("~/takeimage/{item_no}")]
public ActionResult TakeImage(HttpPostedFileBase image, string item_no) {

    return RedirectToAction("DetailsPage", "SK_NO");
}
