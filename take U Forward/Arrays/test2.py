import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from sklearn.datasets import make_blobs
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler
import plotly.express as px

# -------------------------------
# 1️⃣ Generate TRUE 3D Data
# -------------------------------

X, y = make_blobs(
    n_samples=800,
    centers=5,
    n_features=3,      # REAL 3D
    cluster_std=1.2,
    random_state=42
)

df = pd.DataFrame(X, columns=["X", "Y", "Z"])

print("\nDataset Sample:")
print(df.head())

# -------------------------------
# 2️⃣ Standardize
# -------------------------------

scaler = StandardScaler()
X_scaled = scaler.fit_transform(df)

# -------------------------------
# 3️⃣ KMeans Clustering
# -------------------------------

kmeans = KMeans(n_clusters=5, random_state=42)
df["Cluster"] = kmeans.fit_predict(X_scaled)

print("\nCluster Centers:")
print(kmeans.cluster_centers_)

# -------------------------------
# 4️⃣ Static 3D Plot (Matplotlib)
# -------------------------------

fig = plt.figure(figsize=(8, 6))
ax = fig.add_subplot(111, projection='3d')

scatter = ax.scatter(
    df["X"], df["Y"], df["Z"],
    c=df["Cluster"],
    cmap="viridis"
)

ax.set_title("3D KMeans Clustering (Matplotlib)")
ax.set_xlabel("X")
ax.set_ylabel("Y")
ax.set_zlabel("Z")

plt.show()

# -------------------------------
# 5️⃣ 3D Surface Function
# -------------------------------

x = np.linspace(-5, 5, 50)
y = np.linspace(-5, 5, 50)
x, y = np.meshgrid(x, y)
z = np.sin(np.sqrt(x**2 + y**2))

fig2 = plt.figure(figsize=(8, 6))
ax2 = fig2.add_subplot(111, projection='3d')

ax2.plot_surface(x, y, z, cmap="plasma")
ax2.set_title("3D Mathematical Surface")
plt.show()

# -------------------------------
# 6️⃣ INTERACTIVE 3D (Plotly)
# -------------------------------

fig3 = px.scatter_3d(
    df,
    x="X",
    y="Y",
    z="Z",
    color="Cluster",
    title="Interactive 3D Clustering (Rotate Me!)"
)

fig3.show()

print("\n✅ TRUE 3D TEST COMPLETE!")