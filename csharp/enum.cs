// Korzystanie z enum na potrzby zapisywania do bazy danych na podstawie
public enum MessageType {
            warning,
            info,
            danger,
            success,
            primary,
            secondary
        };

private int myVar;
public MessageType MyProperty {
    get { return (MessageType)myVar; }
    set { myVar=(int)value; }
}

// Zrobienei listy wybieralnej na podstawie
public SelectList Select_type = new SelectList(Enum.GetValues(typeof(ObjectType)));
