PM> install-package jquery.datatables

BundleConfig.cs
bundles.Add(new ScriptBundle("~/bundles/datatables").Include(
                        "~/Scripts/DataTables/jquery.datatables.js"
                        , "~/Scripts/DataTables/dataTables.bootstrap.min.js"
                        ));

bundles.Add(new StyleBundle("~/Content/datatables").Include(
    "~/Content/DataTables/css/dataTables.bootstrap.css"
          ));
