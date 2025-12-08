import streamlit as st
import numpy as np
import pickle
from sklearn.preprocessing import StandardScaler

# Load the trained model and scaler
model = pickle.load(open('cardio_model.pkl', 'rb'))
scaler = pickle.load(open('scaler.pkl', 'rb'))

st.title("🏥 Cardiovascular Disease Risk Predictor")

st.write("Fill in the details below to predict probability of cardiac issue:")

age_years = st.slider("Age (years)", 20, 90, 50)
gender = st.selectbox("Gender", ("Male", "Female"))
height = st.number_input("Height (cm)", min_value=100, max_value=220, value=168)
weight = st.number_input("Weight (kg)", min_value=30, max_value=200, value=70)
ap_hi = st.number_input("Systolic BP (ap_hi)", min_value=50, max_value=250, value=120)
ap_lo = st.number_input("Diastolic BP (ap_lo)", min_value=30, max_value=200, value=80)
cholesterol = st.selectbox("Cholesterol Level", ("Normal", "Above Normal", "Well Above Normal"))
gluc = st.selectbox("Glucose Level", ("Normal", "Above Normal", "Well Above Normal"))
smoke = st.selectbox("Do you smoke?", ("Yes", "No"))
alco = st.selectbox("Do you consume alcohol?", ("Yes", "No"))
active = st.selectbox("Are you physically active?", ("Yes", "No"))

bmi = weight / ((height/100) ** 2)
map_value = (2*ap_lo + ap_hi) / 3
pulse_pressure = ap_hi - ap_lo

gender_encoded = 1 if gender == "Female" else 2
cholesterol_encoded = 1 if cholesterol == "Normal" else 2 if cholesterol == "Above Normal" else 3
gluc_encoded = 1 if gluc == "Normal" else 2 if gluc == "Above Normal" else 3
smoke_encoded = 1 if smoke == "Yes" else 0
alco_encoded = 1 if alco == "Yes" else 0
active_encoded = 1 if active == "Yes" else 0

if st.button("Predict"):
    features = np.array([[
        age_years, 
        gender_encoded, 
        height, 
        weight, 
        bmi, 
        ap_hi, 
        ap_lo, 
        map_value, 
        pulse_pressure, 
        cholesterol_encoded, 
        gluc_encoded, 
        smoke_encoded, 
        alco_encoded, 
        active_encoded
    ]])
    
    features_scaled = scaler.transform(features)
    
    prediction = model.predict(features_scaled)
    
    if prediction[0] == 1:
        st.error("⚠️ High risk of cardiac disease. Please consult a doctor.")
    else:
        st.success("✔️ Low risk of cardiac disease. Keep maintaining good health!")
    
    with st.expander("📊 See Input Details"):
        st.write(f"**Age:** {age_years} years")
        st.write(f"**Gender:** {gender}")
        st.write(f"**BMI:** {bmi:.2f}")
        st.write(f"**Blood Pressure:** {ap_hi}/{ap_lo}")
        st.write(f"**Mean Arterial Pressure:** {map_value:.2f}")
        st.write(f"**Pulse Pressure:** {pulse_pressure}")
        
        st.write("\n**Feature Scaling Applied:** ✓")
        st.write("(Features are standardized before prediction)")