$('#the-catalogs .typeahead').typeahead({
            hint: true,
            highlight: true,
            minLength: 1
        },
        {
            name: 'catalogs',
            source: substringMatcher(catalogs_dict)
        }).on("typeahead:select", function (e, catalog) {
            $.each(catalogs_dict, function (key, value) {
                if (catalog == value) {
                    $('#ID_Category').attr('value', key);
                    console.log(key);
                }
            });
        });
