CREATE TABLE autores (
  A_ID  NUMBER NOT NULL AUTO_INCREMENT,
  A_Nombre CHARACTER(15) NOT NULL,
  A_Apellidos CHARACTER(30) NOT NULL,
  A_Nacionalidad CHARACTER(25) NOT NULL,
  A_AreasConocimiento CHARACTER(100) NOT NULL,
  A_Universidad CHARACTER(50) NOT NULL
);

ALTER TABLE autores 
  ADD(PRIMARY KEY(A_ID));

INSERT INTO autores (A_Nombre, A_Apellidos, A_Nacionalidad, A_AreasConocimiento, A_Universidad) VALUES('OSCAR','MMMMM','Español','SOFTWARE','UPM');

