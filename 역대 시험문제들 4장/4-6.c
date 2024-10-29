struct node *temp;

temp->data = data;
temp->link = NULL;
if (front)
    rear->link = temp;
else
    front = temp;
rear = temp;