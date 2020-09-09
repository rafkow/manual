var misitems = new ManageMisItems().GetAllMisItem()                
                .Select(m => new[] { m.SK_NO, m.ITEM_NM, m.PLN_ITEM_NM });

var misitems = new ManageMisItems().GetAllMisItem()
                .Select(m => new { m.SK_NO, m.ITEM_NM, m.PLN_ITEM_NM });
