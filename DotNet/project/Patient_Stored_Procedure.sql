-- EXEC PR_PATIENT_INSERT

CREATE PROCEDURE PR_PATIENT_INSERT

    @NAME           NVARCHAR(100),
    @DATEOFBIRTH    DATETIME,
    @GENDER         NVARCHAR(10),
    @EMAIL          NVARCHAR(100),
    @PHONE          NVARCHAR(100),
    @ADDRESS        NVARCHAR(250),
    @CITY           NVARCHAR(100),
    @STATE          NVARCHAR(100),
    @ISACTIVE       BIT,
    @USERID         INT

AS
BEGIN

    INSERT INTO PATIENT
    VALUES (
        @NAME,
        @DATEOFBIRTH,
        @GENDER,
        @EMAIL,
        @PHONE,
        @ADDRESS,
        @CITY,
        @STATE,
        @ISACTIVE,
        GETDATE(),
        GETDATE(),
        @USERID
    );

END;

-- EXEC PR_PATIENT_UPDATEBYPK

CREATE PROCEDURE PR_PATIENT_UPDATEBYPK

    @PATIENTID      INT,
    @NAME           NVARCHAR(100),
    @DATEOFBIRTH    DATETIME,
    @GENDER         NVARCHAR(10),
    @EMAIL          NVARCHAR(100),
    @PHONE          NVARCHAR(100),
    @ADDRESS        NVARCHAR(250),
    @CITY           NVARCHAR(100),
    @STATE          NVARCHAR(100),
    @ISACTIVE       BIT,
    @USERID         INT

AS
BEGIN

    UPDATE PATIENT
    SET 
        NAME        = @NAME,
        DATEOFBIRTH = @DATEOFBIRTH,
        GENDER      = @GENDER,
        EMAIL       = @EMAIL,
        PHONE       = @PHONE,
        ADDRESS     = @ADDRESS,
        CITY        = @CITY,
        STATE       = @STATE,
        ISACTIVE    = @ISACTIVE,
        MODIFIED    = GETDATE(),
        USERID      = @USERID

    WHERE PATIENTID = @PATIENTID;

END;

-- EXEC PR_PATIENT_DELETEBYPK

CREATE PROCEDURE PR_PATIENT_DELETEBYPK

    @PATIENTID      INT

AS
BEGIN

    DELETE FROM PATIENT
    WHERE PATIENTID = @PATIENTID;

END;

-- EXEC PR_PATIENT_SELECTBYPK 1

CREATE PROCEDURE PR_PATIENT_SELECTBYPK

    @PATIENTID      INT

AS
BEGIN

    SELECT 
        PATIENTID,
        NAME,
        DATEOFBIRTH,
        GENDER,
        EMAIL,
        PHONE,
        ADDRESS,
        CITY,
        STATE,
        ISACTIVE,
        CREATED,
        MODIFIED,
        USERID

    FROM PATIENT
    WHERE PATIENTID = @PATIENTID;

END;

-- EXEC PR_PATIENT_SELECTALL

CREATE PROCEDURE PR_PATIENT_SELECTALL

AS
BEGIN

    SELECT 
        P.PATIENTID,
        P.NAME,
        P.DATEOFBIRTH,
        P.GENDER,
        P.EMAIL,
        P.PHONE,
        P.ADDRESS,
        P.CITY,
        P.STATE,
        P.ISACTIVE,
        P.CREATED,
        P.MODIFIED,
        P.USERID,
        U.USERNAME
    FROM PATIENT P
    INNER JOIN [USER] U ON U.USERID = P.USERID;

END;
