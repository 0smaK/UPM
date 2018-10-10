-- Generado por Oracle SQL Developer Data Modeler 4.1.1.888
--   en:        2018-10-03 12:28:18 CEST
--   sitio:      SQL Server 2012
--   tipo:      SQL Server 2012




CREATE
  TABLE Astronauta
  (
    CodPersona INTEGER NOT NULL
  )
  ON "default"
GO
ALTER TABLE Astronauta ADD CONSTRAINT Astronauta_PK PRIMARY KEY CLUSTERED (
CodPersona)
WITH
  (
    ALLOW_PAGE_LOCKS = ON ,
    ALLOW_ROW_LOCKS  = ON
  )
  ON "default"
GO

CREATE
  TABLE Cientifico
  (
    Cientifico_ID NUMERIC (28) NOT NULL
  )
  ON "default"
GO
ALTER TABLE Cientifico ADD CONSTRAINT Cientifico_PK PRIMARY KEY CLUSTERED (
Cientifico_ID)
WITH
  (
    ALLOW_PAGE_LOCKS = ON ,
    ALLOW_ROW_LOCKS  = ON
  )
  ON "default"
GO

CREATE
  TABLE Cientificov1
  (
    CodPersona INTEGER NOT NULL
  )
  ON "default"
GO
ALTER TABLE Cientificov1 ADD CONSTRAINT Cientificov1_PK PRIMARY KEY CLUSTERED (
CodPersona)
WITH
  (
    ALLOW_PAGE_LOCKS = ON ,
    ALLOW_ROW_LOCKS  = ON
  )
  ON "default"
GO

CREATE
  TABLE Nave
  (
    CodNave INTEGER NOT NULL
  )
  ON "default"
GO
ALTER TABLE Nave ADD CONSTRAINT Nave_PK PRIMARY KEY CLUSTERED (CodNave)
WITH
  (
    ALLOW_PAGE_LOCKS = ON ,
    ALLOW_ROW_LOCKS  = ON
  )
  ON "default"
GO

CREATE
  TABLE Personal
  (
    CodPersona INTEGER NOT NULL ,
    Tipo UNKNOWN
    --  ERROR: Datatype UNKNOWN is not allowed
    NOT NULL ,
    CodPersona2              INTEGER ,
    Cientifico_Cientifico_ID NUMERIC (28) ,
    Tecnico_Tecnico_ID       NUMERIC (28)
  )
  ON "default"
GO
ALTER TABLE Personal
ADD CONSTRAINT FKArc_1 CHECK (
( (CodPersona2 IS NOT NULL) AND
(
  Cientifico_Cientifico_ID IS NULL
)
AND
(
  Tecnico_Tecnico_ID IS NULL
)
) OR
(
  (
    Cientifico_Cientifico_ID IS NOT NULL
  )
  AND
  (
    CodPersona2 IS NULL
  )
  AND
  (
    Tecnico_Tecnico_ID IS NULL
  )
)
OR
(
  (
    Tecnico_Tecnico_ID IS NOT NULL
  )
  AND
  (
    CodPersona2 IS NULL
  )
  AND
  (
    Cientifico_Cientifico_ID IS NULL
  )
)
)
;
ALTER TABLE Personal ADD CONSTRAINT Personal_PK PRIMARY KEY CLUSTERED (
CodPersona)
WITH
  (
    ALLOW_PAGE_LOCKS = ON ,
    ALLOW_ROW_LOCKS  = ON
  )
  ON "default"
GO

CREATE
  TABLE Tecnico
  (
    Tecnico_ID NUMERIC (28) NOT NULL
  )
  ON "default"
GO
ALTER TABLE Tecnico ADD CONSTRAINT Tecnico_PK PRIMARY KEY CLUSTERED (Tecnico_ID
)
WITH
  (
    ALLOW_PAGE_LOCKS = ON ,
    ALLOW_ROW_LOCKS  = ON
  )
  ON "default"
GO

CREATE
  TABLE Tecnicov1
  (
    CodPersona INTEGER NOT NULL
  )
  ON "default"
GO
ALTER TABLE Tecnicov1 ADD CONSTRAINT Tecnicov1_PK PRIMARY KEY CLUSTERED (
CodPersona)
WITH
  (
    ALLOW_PAGE_LOCKS = ON ,
    ALLOW_ROW_LOCKS  = ON
  )
  ON "default"
GO

CREATE
  TABLE maneja_a
  (
    Astronauta_CodPersona INTEGER NOT NULL ,
    Nave_CodNave          INTEGER NOT NULL ,
    Fe UNKNOWN
    --  ERROR: Datatype UNKNOWN is not allowed
  )
  ON "default"
GO
ALTER TABLE maneja_a ADD CONSTRAINT maneja_a_PK PRIMARY KEY CLUSTERED (
Astronauta_CodPersona, Nave_CodNave)
WITH
  (
    ALLOW_PAGE_LOCKS = ON ,
    ALLOW_ROW_LOCKS  = ON
  )
  ON "default"
GO

CREATE
  TABLE mision
  (
    CodMision INTEGER NOT NULL ,
    conclus   INTEGER ,
    Ff        INTEGER
  )
  ON "default"
GO
ALTER TABLE mision ADD CONSTRAINT mision_PK PRIMARY KEY CLUSTERED (CodMision)
WITH
  (
    ALLOW_PAGE_LOCKS = ON ,
    ALLOW_ROW_LOCKS  = ON
  )
  ON "default"
GO

CREATE
  TABLE participan
  (
    Astronauta_CodPersona INTEGER NOT NULL ,
    mision_CodMision      INTEGER NOT NULL ,
    Fi                    INTEGER ,
    Ff                    INTEGER
  )
  ON "default"
GO
ALTER TABLE participan ADD CONSTRAINT participan_PK PRIMARY KEY CLUSTERED (
Astronauta_CodPersona, mision_CodMision)
WITH
  (
    ALLOW_PAGE_LOCKS = ON ,
    ALLOW_ROW_LOCKS  = ON
  )
  ON "default"
GO

CREATE
  TABLE propuesta
  (
    Cientifico_Cientifico_ID NUMERIC (28) NOT NULL ,
    mision_CodMision         INTEGER NOT NULL ,
    Fech                     DATE
  )
  ON "default"
GO
ALTER TABLE propuesta ADD CONSTRAINT propuesta_PK PRIMARY KEY CLUSTERED (
Cientifico_Cientifico_ID, mision_CodMision)
WITH
  (
    ALLOW_PAGE_LOCKS = ON ,
    ALLOW_ROW_LOCKS  = ON
  )
  ON "default"
GO

CREATE
  TABLE realizan
  (
    Nave_CodNave     INTEGER NOT NULL ,
    mision_CodMision INTEGER NOT NULL ,
    Fi               INTEGER ,
    Ff               INTEGER
  )
  ON "default"
GO
ALTER TABLE realizan ADD CONSTRAINT realizan_PK PRIMARY KEY CLUSTERED (
Nave_CodNave, mision_CodMision)
WITH
  (
    ALLOW_PAGE_LOCKS = ON ,
    ALLOW_ROW_LOCKS  = ON
  )
  ON "default"
GO

ALTER TABLE propuesta
ADD CONSTRAINT FK_ASS_10 FOREIGN KEY
(
mision_CodMision
)
REFERENCES mision
(
CodMision
)
ON
DELETE
  NO ACTION ON
UPDATE NO ACTION
GO

ALTER TABLE realizan
ADD CONSTRAINT FK_ASS_11 FOREIGN KEY
(
Nave_CodNave
)
REFERENCES Nave
(
CodNave
)
ON
DELETE
  NO ACTION ON
UPDATE NO ACTION
GO

ALTER TABLE realizan
ADD CONSTRAINT FK_ASS_12 FOREIGN KEY
(
mision_CodMision
)
REFERENCES mision
(
CodMision
)
ON
DELETE
  NO ACTION ON
UPDATE NO ACTION
GO

ALTER TABLE maneja_a
ADD CONSTRAINT FK_ASS_5 FOREIGN KEY
(
Astronauta_CodPersona
)
REFERENCES Astronauta
(
CodPersona
)
ON
DELETE
  NO ACTION ON
UPDATE NO ACTION
GO

ALTER TABLE maneja_a
ADD CONSTRAINT FK_ASS_6 FOREIGN KEY
(
Nave_CodNave
)
REFERENCES Nave
(
CodNave
)
ON
DELETE
  NO ACTION ON
UPDATE NO ACTION
GO

ALTER TABLE participan
ADD CONSTRAINT FK_ASS_7 FOREIGN KEY
(
Astronauta_CodPersona
)
REFERENCES Astronauta
(
CodPersona
)
ON
DELETE
  NO ACTION ON
UPDATE NO ACTION
GO

ALTER TABLE participan
ADD CONSTRAINT FK_ASS_8 FOREIGN KEY
(
mision_CodMision
)
REFERENCES mision
(
CodMision
)
ON
DELETE
  NO ACTION ON
UPDATE NO ACTION
GO

ALTER TABLE propuesta
ADD CONSTRAINT FK_ASS_9 FOREIGN KEY
(
Cientifico_Cientifico_ID
)
REFERENCES Cientifico
(
Cientifico_ID
)
ON
DELETE
  NO ACTION ON
UPDATE NO ACTION
GO

ALTER TABLE Personal
ADD CONSTRAINT Personal_Astronauta_FK FOREIGN KEY
(
CodPersona2
)
REFERENCES Astronauta
(
CodPersona
)
ON
DELETE
  NO ACTION ON
UPDATE NO ACTION
GO

ALTER TABLE Personal
ADD CONSTRAINT Personal_Cientifico_FK FOREIGN KEY
(
Cientifico_Cientifico_ID
)
REFERENCES Cientifico
(
Cientifico_ID
)
ON
DELETE
  NO ACTION ON
UPDATE NO ACTION
GO

ALTER TABLE Personal
ADD CONSTRAINT Personal_Tecnico_FK FOREIGN KEY
(
Tecnico_Tecnico_ID
)
REFERENCES Tecnico
(
Tecnico_ID
)
ON
DELETE
  NO ACTION ON
UPDATE NO ACTION
GO


-- Informe de Resumen de Oracle SQL Developer Data Modeler: 
-- 
-- CREATE TABLE                            12
-- CREATE INDEX                             0
-- ALTER TABLE                             24
-- CREATE VIEW                              0
-- ALTER VIEW                               0
-- CREATE PACKAGE                           0
-- CREATE PACKAGE BODY                      0
-- CREATE PROCEDURE                         0
-- CREATE FUNCTION                          0
-- CREATE TRIGGER                           0
-- ALTER TRIGGER                            0
-- CREATE DATABASE                          0
-- CREATE DEFAULT                           0
-- CREATE INDEX ON VIEW                     0
-- CREATE ROLLBACK SEGMENT                  0
-- CREATE ROLE                              0
-- CREATE RULE                              0
-- CREATE SCHEMA                            0
-- CREATE SEQUENCE                          0
-- CREATE PARTITION FUNCTION                0
-- CREATE PARTITION SCHEME                  0
-- 
-- DROP DATABASE                            0
-- 
-- ERRORS                                   2
-- WARNINGS                                 0

