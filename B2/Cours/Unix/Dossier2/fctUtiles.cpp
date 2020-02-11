void MainDeuxiemeDossierUnix2019::setNom(const char* Text)
{
if (Text == NULL || strlen(Text) == 0 ) 
   { 
   ui->lineNom->clear();
   return;
   }
ui->lineNom->setText(Text);
return;
}

const char* MainDeuxiemeDossierUnix2019::getNom() const
{
static char			Nom[255];

if (ui->lineNom->text().size())
	{ 
	strcpy(Nom,ui->lineNom->text().toStdString().c_str());
	return Nom;
	}
return NULL;
}

void MainDeuxiemeDossierUnix2019::setAdresseMail(const char* Text)
{
if (Text == NULL || strlen(Text) == 0 ) 
   { 
   ui->lineAdresseMail->clear();
   return;
   }
ui->lineAdresseMail->setText(Text);
return;
}

const char* MainDeuxiemeDossierUnix2019::getAdresseMail() const
{
static char			Mail[255];

if (ui->lineAdresseMail->text().size())
	{ 
	strcpy(Mail,ui->lineAdresseMail->text().toStdString().c_str());
	return Mail;
	}
return NULL;
}

void MainDeuxiemeDossierUnix2019::setAnneeNaissance(int Nb)
{
char	Text[8];
if (Nb == 0 ) 
   { 
   ui->lineAnneeNaissance->clear();
   return;
   }
sprintf(Text,"%d",Nb);
ui->lineAnneeNaissance->setText(Text);
return;
}


void MainDeuxiemeDossierUnix2019::setFichierImage(const char* Text)
{
if (Text == NULL || strlen(Text) == 0 ) 
   { 
   ui->lineFichierImage->clear();
   return;
   }
ui->lineFichierImage->setText(Text);
return;
}

const char* MainDeuxiemeDossierUnix2019::getFichierImage() const
{
static char			FichierImage[255];

if (ui->lineFichierImage->text().size())
	{ 
	strcpy(FichierImage,ui->lineFichierImage->text().toStdString().c_str());
	return FichierImage;
	}
return NULL;
}

void MainDeuxiemeDossierUnix2019::setImage(const char* Image)
{
char	Buff[256];
sprintf(Buff,"./Images/%s",Image);
    QPixmap Pix(Buff);
    ui->labelImage ->setPixmap(Pix);
    ui->labelImage->setScaledContents(true);
}

void MainDeuxiemeDossierUnix2019::setTextModifier(const char* Texte)
{
ui->ButtonModifier->setText(Texte);
return;
}

bool MainDeuxiemeDossierUnix2019::MessageConfirmation(const char* T,const char* Texte)
{
 QMessageBox::StandardButton Reponse = QMessageBox::question(this,T,Texte,QMessageBox::Yes|QMessageBox::No);
      if (Reponse == QMessageBox::Yes) return true;
      else return false;;
 }
