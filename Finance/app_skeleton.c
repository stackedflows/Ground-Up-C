  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gtk/gtk.h>

GtkEntry * gas;
GtkEntry * electric;
GtkEntry * rent;
GtkEntry * internet;
GtkEntry * food;
GtkEntry * petrol;
GtkEntry * parking;
GtkEntry * other;

GtkEntry * job;
GtkEntry * investment;
GtkEntry * games;
GtkEntry * i_other;

GtkLabel * summary;

int main(int argc, char *argv[]){
    //GTK initialise
    GtkBuilder *builder;
    GtkWidget *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("glade/main.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "main"));
    gtk_builder_connect_signals(builder, NULL);

    gas = malloc(sizeof(GtkEntry *));
    gas = GTK_ENTRY(gtk_builder_get_object(builder, "gas_"));
    electric = malloc(sizeof(GtkEntry *));
    electric = GTK_ENTRY(gtk_builder_get_object(builder, "electric_"));
    rent = malloc(sizeof(GtkEntry *));
    rent = GTK_ENTRY(gtk_builder_get_object(builder, "rent_"));
    internet = malloc(sizeof(GtkEntry *));
    internet = GTK_ENTRY(gtk_builder_get_object(builder, "internet_"));
    food = malloc(sizeof(GtkEntry *));
    food = GTK_ENTRY(gtk_builder_get_object(builder, "food_"));
    petrol = malloc(sizeof(GtkEntry *));
    petrol = GTK_ENTRY(gtk_builder_get_object(builder, "petrol_"));
    parking = malloc(sizeof(GtkEntry *));
    parking = GTK_ENTRY(gtk_builder_get_object(builder, "parking_"));
    other = malloc(sizeof(GtkEntry *));
    other = GTK_ENTRY(gtk_builder_get_object(builder, "other_"));

    job = malloc(sizeof(GtkEntry *));
    job = GTK_ENTRY(gtk_builder_get_object(builder, "job_"));
    investment = malloc(sizeof(GtkEntry *));
    investment = GTK_ENTRY(gtk_builder_get_object(builder, "investment_"));
    games = malloc(sizeof(GtkEntry *));
    games = GTK_ENTRY(gtk_builder_get_object(builder, "games_"));
    i_other = malloc(sizeof(GtkEntry *));
    i_other = GTK_ENTRY(gtk_builder_get_object(builder, "other__"));

    summary = GTK_LABEL(gtk_builder_get_object(builder, "summary_"));

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();

    return 0;
}

int sum_in_elements(){
  const gchar * reset = "";
  const gchar * job_entry = gtk_entry_get_text(job);
  const gchar * investment_entry = gtk_entry_get_text(investment);
  const gchar * games_entry = gtk_entry_get_text(games);
  const gchar * i_other_entry = gtk_entry_get_text(i_other);
  int sum = 0;
  if(job_entry[0] == 0 || investment_entry[0] == 0 || games_entry[0] == 0|| i_other_entry[0] == 0){
    return 0;
  }else{
    sum = sum + atoi(i_other_entry) + atoi(games_entry) + atoi(investment_entry) + atoi(job_entry);
  }
  gtk_entry_set_text(job, reset);
  gtk_entry_set_text(investment, reset);
  gtk_entry_set_text(games, reset);
  gtk_entry_set_text(i_other, reset);
  return sum;
}

int sum_out_elements(){
  const gchar * reset = "";
  const gchar * gas_entry = gtk_entry_get_text(gas);
  const gchar * electric_entry = gtk_entry_get_text(electric);
  const gchar * rent_entry = gtk_entry_get_text(rent);
  const gchar * internet_entry = gtk_entry_get_text(internet);
  const gchar * food_entry = gtk_entry_get_text(food);
  const gchar * petrol_entry = gtk_entry_get_text(petrol);
  const gchar * parking_entry = gtk_entry_get_text(parking);
  const gchar * other_entry = gtk_entry_get_text(other);
  int sum = 0;
  if(gas_entry[0] == 0 || electric_entry[0] == 0 || rent_entry[0] == 0|| internet_entry[0] == 0){
    return 0;
  }else if(food_entry[0] == 0 || petrol_entry[0] == 0 || parking_entry[0] == 0|| other_entry[0] == 0){
    return 0;
  }else{
    sum = sum + atoi(gas_entry) + atoi(electric_entry) + atoi(rent_entry) + atoi(internet_entry);
    sum = sum + atoi(food_entry) + atoi(petrol_entry) + atoi(parking_entry) + atoi(other_entry);
  }
  gtk_entry_set_text(gas, reset);
  gtk_entry_set_text(electric, reset);
  gtk_entry_set_text(rent, reset);
  gtk_entry_set_text(internet, reset);
  gtk_entry_set_text(food, reset);
  gtk_entry_set_text(petrol, reset);
  gtk_entry_set_text(parking, reset);
  gtk_entry_set_text(other, reset);
  return sum;
}

void on_submit_clicked(){
  //GTK handling
  const gchar * reset = "";
  gtk_label_set_text(summary, reset);

  int _sum;
  _sum = sum_in_elements() - sum_out_elements();

  int check_if_new;
  FILE * new = fopen("new.txt", "w+");
  fscanf(new, "%d", &check_if_new);
  fclose(new);

  int stored;

  if(check_if_new != 0){

    FILE * data = fopen("this.txt", "w+");
    fprintf(data, "%d", _sum);
    fclose(data);

    FILE * new = fopen("new.txt", "w+");
    fprintf(new, "%d", 0);
    fclose(new);

  }else{
    FILE * data = fopen("this.txt", "w+");
    fscanf(data, "%d", &stored);
    fprintf(data, "%d", _sum + stored);
    fclose(data);
  }

  char str[MAX_];
  sprintf(str, "%d", _sum);

  const gchar * k;
  k = str;
  gtk_label_set_text(summary, k);
}


void on_main_destroy(){
    gtk_main_quit();
}
