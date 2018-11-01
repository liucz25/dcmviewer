
# coding: utf-8

# In[1]:


from tvtk.api import tvtk


# In[2]:


d=tvtk.DICOMImageReader(file_name="3.dcm")


# In[3]:


d.update()


# In[5]:


im=tvtk.ImageViewer2()


# In[20]:


im.set_input_connection(d.output_port)


# In[21]:


rwi=tvtk.RenderWindowInteractor()


# In[22]:


im.setup_interactor(rwi)


# In[23]:


im.render()


# In[24]:


rwi.start()

