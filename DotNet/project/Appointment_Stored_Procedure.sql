-- EXEC PR_APPOINTMENT_INSERT

CREATE PROCEDURE PR_APPOINTMENT_INSERT

    @DOCTORID               INT,
    @PATIENTID              INT,
    @APPOINTMENTDATE        DATETIME,
    @APPOINTMENTSTATUS      NVARCHAR(20),
    @DESCRIPTION            NVARCHAR(250),
    @SPECIALREMARKS         NVARCHAR(100),
    @USERID                 INT,
    @TOTALCONSULTEDAMOUNT   DECIMAL(10,2)

AS
BEGIN

    INSERT INTO APPOINTMENT 
    VALUES (
        @DOCTORID,
        @PATIENTID,
        @APPOINTMENTDATE,
        @APPOINTMENTSTATUS,
        @DESCRIPTION,
        @SPECIALREMARKS,
        GETDATE(),
        GETDATE(),
        @USERID,
        @TOTALCONSULTEDAMOUNT
    );

END;

-- EXEC PR_APPOINTMENT_UPDATEBYPK

CREATE PROCEDURE PR_APPOINTMENT_UPDATEBYPK

    @APPOINTMENTID          INT,
    @DOCTORID               INT,
    @PATIENTID              INT,
    @APPOINTMENTDATE        DATETIME,
    @APPOINTMENTSTATUS      NVARCHAR(20),
    @DESCRIPTION            NVARCHAR(250),
    @SPECIALREMARKS         NVARCHAR(100),
    @USERID                 INT,
    @TOTALCONSULTEDAMOUNT   DECIMAL(10,2)

AS
BEGIN

    UPDATE APPOINTMENT
    SET 
        DOCTORID              =    @DOCTORID,
        PATIENTID             =    @PATIENTID,
        APPOINTMENTDATE       =    @APPOINTMENTDATE,
        APPOINTMENTSTATUS     =    @APPOINTMENTSTATUS,
        [DESCRIPTION]         =    @DESCRIPTION,
        SPECIALREMARKS        =    @SPECIALREMARKS,
        MODIFIED              =    GETDATE(),
        USERID                =    @USERID,
        TOTALCONSULTEDAMOUNT  =    @TOTALCONSULTEDAMOUNT

    WHERE APPOINTMENTID = @APPOINTMENTID;

END;

-- EXEC PR_APPOINTMENT_DELETEBYPK

CREATE PROCEDURE PR_APPOINTMENT_DELETEBYPK

    @APPOINTMENTID      INT

AS
BEGIN

    DELETE FROM APPOINTMENT
    WHERE APPOINTMENTID = @APPOINTMENTID;

END;


-- EXEC PR_APPOINTMENT_SELECTBYID 1

CREATE PROCEDURE PR_APPOINTMENT_SELECTBYID

    @APPOINTMENTID      INT

AS
BEGIN

    SELECT 
        APPOINTMENTID,
        DOCTORID,
        PATIENTID,
        APPOINTMENTDATE,
        APPOINTMENTSTATUS,
        [DESCRIPTION],
        SPECIALREMARKS,
        CREATED,
        MODIFIED,
        USERID,
        TOTALCONSULTEDAMOUNT

    FROM APPOINTMENT
    WHERE APPOINTMENTID = @APPOINTMENTID;

END;


-- EXEC PR_APPOINTMENT_SELECTALL

CREATE PROCEDURE PR_APPOINTMENT_SELECTALL

AS
BEGIN

    SELECT 
        A.APPOINTMENTID,
        A.DOCTORID,
        D.NAME AS DOCTORNAME,
        A.PATIENTID,
        P.NAME AS PATIENTNAME,
        A.APPOINTMENTDATE,
        A.APPOINTMENTSTATUS,
        A.[DESCRIPTION],
        A.SPECIALREMARKS,
        A.CREATED,
        A.MODIFIED,
        A.USERID,
        U.USERNAME,
        A.TOTALCONSULTEDAMOUNT
    FROM APPOINTMENT A
    INNER JOIN DOCTOR D ON D.DOCTORID = A.DOCTORID
    INNER JOIN PATIENT P ON P.PATIENTID = A.PATIENTID
    INNER JOIN [USER] U ON U.USERID = A.USERID;

END;

