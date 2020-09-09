{% for field in form.object_fields %}
            {{ forloop.counter }}
            {{ field.forloop.counter }}
        {% endfor %}
